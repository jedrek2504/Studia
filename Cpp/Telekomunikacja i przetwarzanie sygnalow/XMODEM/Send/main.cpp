#include <iostream>
#include <fstream>
#include <windows.h>
#include <winbase.h>
#include <conio.h>

using namespace std;

const char SOH = (char) 0x01;
const char NAK = (char) 0x15;
const char CAN = (char) 0x18;
const char ACK = (char) 0x06;
const char EOT = (char) 0x04;

HANDLE const_handle;
LPCTSTR const_lpctstr;
DCB const_dcb;
USHORT const_ushort;


int portSettings(LPCTSTR const_lpctstrF) //NADANIE PORTOWI PARAMETROW + OTWORZENIE GO
{
    if (const_handle == INVALID_HANDLE_VALUE) {
        return 0;
    } else {
        const_handle = CreateFile(const_lpctstrF, GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
        const_dcb.DCBlength = sizeof(const_dcb); // Set the length of the DCB (Device Control Block) structure to the size of the constant DCB structure.
        const_dcb.BaudRate = CBR_9600; // Set the baud rate to 9600.
        const_dcb.fParity = TRUE; // Enable parity checking.
        const_dcb.Parity = NOPARITY; // Set parity to none.
        const_dcb.StopBits = ONESTOPBIT; // Set the number of stop bits to one.
        const_dcb.ByteSize = 8; // Set the number of data bits to eight.
        const_dcb.fDtrControl = DTR_CONTROL_DISABLE; // Disable DTR control.
        const_dcb.fRtsControl = RTS_CONTROL_DISABLE; // Disable RTS control.
        const_dcb.fOutxCtsFlow = FALSE; // Disable CTS flow control.
        const_dcb.fOutxDsrFlow = FALSE; // Disable DSR flow control.
        const_dcb.fDsrSensitivity = FALSE; // Disable DSR sensitivity.
        const_dcb.fAbortOnError = FALSE; // Do not abort communication on error.
        const_dcb.fOutX = FALSE; // Disable XON/XOFF flow control for transmission.
        const_dcb.fInX = FALSE; // Disable XON/XOFF flow control for reception.
        const_dcb.fErrorChar = FALSE; // Disable replacement of erroneous bytes with specified characters.
        const_dcb.fNull = FALSE; // Do not discard null bytes.

        return 1;
    }
}

// This function calculates the CRC checksum of a given data block.
// It takes a pointer to the block of data and the count of bytes in the block as input.
// It returns the calculated CRC checksum as an integer value.
int checkCRC(char *point, int count) {
    int CRCchecksum = 0;

    // loop through all bytes in the data block
    while (--count >= 0) {
        // XOR the current byte with the checksum shifted by 8 bits and assign the result to the checksum
        CRCchecksum = CRCchecksum ^ (int) *point++ << 8;

        // loop through each bit of the current byte
        for (int i = 0; i < 8; ++i) {
            // if the leftmost bit of the checksum is 1, XOR the checksum with the generator polynomial 0x1021
            if (CRCchecksum & 0x8000)
                CRCchecksum = CRCchecksum << 1 ^ 0x1021;
                // otherwise, shift the checksum to the left by 1 bit
            else
                CRCchecksum = CRCchecksum << 1;
        }

    }
    // return the lower 16 bits of the checksum as the final CRC value
    return (CRCchecksum & 0xFFFF);
}

// Converts a binary number to decimal
int binToDec(int y) {
    if (y == 0) return 1; // If the binary number is 0, the decimal equivalent is 1
    if (y == 1) return 2; // If the binary number is 1, the decimal equivalent is 2

    int result = 2; // Start with the value of 2 (equivalent to binary 10)

    // For each bit in the binary number after the first two, double the current value of the result
    for (int i = 2; i <= y; i++)
        result = result * 2;

    return result; // Return the final result
}



char checkCRCsign(int CRC, int signNumber) // Function to convert CRC checksum to binary form
{
    int tmp, binary[16];

    // Initialize binary array with zeros
    for (int i = 0; i < 16; i++)
        binary[i] = 0;

    // Convert CRC to binary and store in binary array
    for (int i = 0; i < 16; i++) {
        tmp = CRC % 2;
        if (tmp == 1) CRC = (CRC - 1) / 2;
        if (tmp == 0) CRC = CRC / 2;
        binary[15 - i] = tmp;
    }

    // Calculate the first or second character of the received CRC
    tmp = 0;
    int h;

    if (signNumber == 1) h = 7; // Calculate the first character
    if (signNumber == 2) h = 15; // Calculate the second character

    // Calculate the value of the character based on the binary value
    for (int i = 0; i < 8; i++)
        tmp = tmp + binToDec(i) * binary[h - i];

    // Return the calculated character
    return (char) tmp; // Returns the first or second character (since 2 characters make up 2 bytes, i.e. 16 bits)
}


int main() {
    unsigned char sign;
    long unsigned int sizeOfSign = sizeof(sign);
    ifstream sendTXT;
    char data[128];
    int blockNumber = 1;
    bool gotACK = false;

    //MENU
    char choice;
    cout << "Wybierz opcje:\n"
         << "[1] - COM1\n"
         << "[2] - COM2\n"
         << "[3] - COM3\n"
         << "[4] - COM4\n"
         << "[q] - Zakoncz program\n";
    cin >> choice;

    switch (choice) {
        case '1':
            const_lpctstr = "COM1";
            cout << "Wybrano COM1\n";
            break;
        case '2':
            const_lpctstr = "COM2";
            cout << "Wybrano COM2\n";
            break;
        case '3':
            const_lpctstr = "COM3";
            cout << "Wybrano COM3\n";
            break;
        case '4':
            const_lpctstr = "COM4";
            cout << "Wybrano COM4\n";
            break;
        case 'q':
        default:
            cout << "\nExiting...";
            return 0;
    }

    // set settings to chosen port
    portSettings(const_lpctstr);

    //handshake - establishing connection
    for (int i = 0; i < 6; i++) {
        cout << "Ustanawianie polaczenia...\n";
        // Read a single byte from a handle and store it in the variable "sign"
        ReadFile(const_handle, &sign, 1, &sizeOfSign, nullptr);

        // If the received byte is 'C', print message indicating an ACK has been received and set "gotACK" flag to true
        if (sign == 'C') {
            cout << "Otrzymano C.\n";
            gotACK = true;
            break;
        }

        // If the received byte is NACK, print message indicating a NACK has been received and set "gotACK" flag to false
        else if (sign == NAK) {
            cout << "Otrzymano NACK.\n";
            gotACK = false;
            break;
        }
    }

    sendTXT.open(R"(C:\Users\jedre\DreamTeam\tele\zad2\Zad2 (send)\sendTXT.txt)",  ios::binary);
    cout << "Trwa wysylanie pliku...\n";

    //SEND DATA
    while (!sendTXT.eof()) {
        // Loop through 128 characters to fill the data array
        for (int i = 0; i < 128; i++) {
            bool fillTo128;

            // If not the end of the file, add the character to the data array
            if (!sendTXT.eof()) {
                data[i] = static_cast<char>(sendTXT.get());
                if (sendTXT.eof()) {
                    data[i] = (char) 26;
                }
            }

            // If the end of the file is reached, add a space character to the data array and set fillTo128 to true
            else if (sendTXT.eof()) {
                data[i] = ' ';
                fillTo128 = true;
            }

            // If fillTo128 is true, loop through the remaining elements with blank spaces
            if (fillTo128) {
                for (int j = i + 1; j < 128; j++) {
                    data[j] = ' ';
                }
            }

        }


        while (true) {
            cout << "Wysylanie " << blockNumber << ". pakietu ";

            // Send start of header character
            WriteFile(const_handle, &SOH, 1, &sizeOfSign, nullptr);

            // Send block number (1 byte)
            sign = static_cast<unsigned char>(blockNumber);
            WriteFile(const_handle, &sign, 1, &sizeOfSign, nullptr);

            // Send complement of block number (1 byte)
            sign = static_cast<unsigned char>(255 - blockNumber);
            WriteFile(const_handle, &sign, 1, &sizeOfSign, nullptr);

            // Send data
            for (int i = 0; i < 128; i++) {
                WriteFile(const_handle, &data[i], 1, &sizeOfSign, nullptr);
            }

            // If ACK received, calculate CRC and send
            if (gotACK) {
                const_ushort = checkCRC(data, 128);
                sign = checkCRCsign(const_ushort, 1);
                WriteFile(const_handle, &sign, 1, &sizeOfSign, nullptr);

                sign = checkCRCsign(const_ushort, 2);
                WriteFile(const_handle, &sign, 1, &sizeOfSign, nullptr);
            }
            // If NAK received, calculate control sum and send
            else {
                sign = (char) 0x00;
                for (int i = 0; i < 128; i++) {
                    sign += data[i];
                }
                sign = sign % 256;
                WriteFile(const_handle, &sign, 1, &sizeOfSign, nullptr);
            }

            // Read response from receiver
            sign = ' ';
            ReadFile(const_handle, &sign, 1, &sizeOfSign, nullptr);

            // Check response
            if (sign == ACK) {
                cout << "powiodlo sie.\n";
                break;
            } else if (sign == NAK) {
                cout << "NIE powiodlo sie (NAK).\n";
                break;
            } else if (sign == CAN) {
                cout << "NIE powiodlo sie (polaczenie przerwane).\n";
                return 0;
            }
        }

        // if block number is larger than 255 then reset the counter
        if (blockNumber == 255)
            blockNumber = 1;
        else
            blockNumber++;
    }

    sendTXT.close();

    // This loop sends EOT (end of transmission) until it receives an ACK (acknowledge) signal or the connection is lost.
    while (true) {
        sign = EOT;
        WriteFile(const_handle, &sign, 1, &sizeOfSign, nullptr); // Send EOT signal.
        ReadFile(const_handle, &sign, 1, &sizeOfSign, nullptr); // Wait for response.

        if (sign == ACK) {
            // If ACK is received, break the loop.
            break;
        }
    }

    // closing handle and ending program
    CloseHandle(const_handle);
    cout << "Plik zostal wyslany w calosci.\n";

    return 0;
}
