#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <winbase.h>
#include <chrono>
#include <thread>


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

// Applying parameters to chosen port + opening it
int portSettings(LPCTSTR lpctstr)
{
    if (const_handle == INVALID_HANDLE_VALUE) {
        return 0;
    } else {
        const_handle = CreateFile(lpctstr, GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
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
    int CRCcheckSum = 0;

    // loop through all bytes in the data block
    while (--count >= 0) {
        // XOR the current byte with the checksum shifted by 8 bits and assign the result to the checksum
        CRCcheckSum = CRCcheckSum ^ (int) *point++ << 8;

        // loop through each bit of the current byte
        for (int i = 0; i < 8; ++i) {
            // if the leftmost bit of the checksum is 1, XOR the checksum with the generator polynomial 0x1021
            if (CRCcheckSum & 0x8000)
                CRCcheckSum = CRCcheckSum << 1 ^ 0x1021;
                // otherwise, shift the checksum to the left by 1 bit
            else
                CRCcheckSum = CRCcheckSum << 1;
        }

    }
    // return the lower 16 bits of the checksum as the final CRC value
    return (CRCcheckSum & 0xFFFF);
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

// Function to convert CRC checksum to binary form
char checkCRCsign(int CRC, int signNumber)
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
    char sign;
    long unsigned int sizeOfSign = sizeof(sign);
    ofstream receiveTXT;
    char data[128];
    int blockNumber = 0;
    char fillTo255;
    bool rightPackage;
    char receivedCRC[2];

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
            cout << "\nExiting...\n";
            return 0;
    }

    // set settings to chosen port
    portSettings(const_lpctstr);

    cout << "Wybierz opcje:\n"
         << "[1] - C\n"
         << "[2] - NAK\n";
    cin >> choice;

    // asign value to sign variable based on users choice.
    switch (choice) {
        case '1': {
            sign = 'C'; // Set the value of the "sign" variable to 'C'
            cout << "Wybrano C\n";
            break;
        }
        case '2': {
            sign = NAK; // Set the value of the "sign" variable to the constant "NAK"
            cout << "Wybrano NAK\n";
            break;
        }
        default: {
            cout << "\nExiting...\n";
            return 0;
        }
    }

    // handshake
    for (int i = 0; i < 6; i++) {
        WriteFile(const_handle, &sign, 1, &sizeOfSign, nullptr); // Send the value of the "sign" variable over the connection
        cout << "Ustanawianie polaczenia...\n";
        ReadFile(const_handle, &sign, 1, &sizeOfSign, nullptr); // Wait for a response from the other end of the connection

        // Check the value of the "sign" variable to see if the connection has been established
        if (sign == SOH) {
            cout << "Polaczenie zostalo ustanowione.\n";
            break; // Exit the loop
        }
    }

    // if sign != SOH it means that handshake was unsuccessful
    if (sign != SOH) {
        cout << "Nie udalo sie ustanowic polaczenia.\n";
        return 0;
    }

    receiveTXT.open(R"(C:\Users\jedre\DreamTeam\tele\zad2\Zad2 (receive)\receiveTXT.txt)",  ios::binary);
    cout << "Trwa odbieranie pliku...\n";

    // RECEIVE DATA
    // This is a while loop that reads data from a file and checks for errors
    while (true) {
        if (blockNumber != 0) //it has already been made to first block during handshake
        {
            ReadFile(const_handle, &sign, 1, &sizeOfSign, nullptr); //sign == SOH || EOT || CAN
            if (sign == EOT || sign == CAN) break; // if EOT or CAN has been recieved then break loop
        }

        ReadFile(const_handle, &sign, 1, &sizeOfSign, nullptr); //sign == block number

        blockNumber = (int) (static_cast<unsigned char>(sign));

        ReadFile(const_handle, &sign, 1, &sizeOfSign, nullptr); //sign == 255 - block number
        fillTo255 = sign;

        for (int i = 0; i < 128; i++) {
            ReadFile(const_handle, &sign, 1, &sizeOfSign,nullptr); //sign == letter, done 128 times -> 128 byte block of data
            data[i] = sign;
        }
        rightPackage = true;

        // Check if the block number is correct
        if ((char) (255 - blockNumber) != fillTo255) {
            cout << "Niepoprawny numer pakietu.\n";
            WriteFile(const_handle, &NAK, 1, &sizeOfSign, nullptr); // send NAK
            rightPackage = false;
        }


       if (choice == '1') { // if we chose '1' -> we use CRC
           // Reads two bytes of CRC checksum from the serial port and calculates the CRC checksum of the received data
            ReadFile(const_handle, &sign, 1, &sizeOfSign, nullptr);
            receivedCRC[0] = sign;
            ReadFile(const_handle, &sign, 1, &sizeOfSign, nullptr);
            receivedCRC[1] = sign;
            const_ushort = checkCRC(data, 128);

            // If the calculated checksum does not match the received checksum, sends NAK to indicate an error in the received package
            if (checkCRCsign(const_ushort, 1) != receivedCRC[0] || checkCRCsign(const_ushort, 2) != receivedCRC[1]) {
                cout << "Niepoprawna suma kontrolna.\n";
                WriteFile(const_handle, &NAK, 1, &sizeOfSign, nullptr);
                rightPackage = false; // Sets rightPackage to false indicating a package error has occurred
            }
        } else { // if we chose '2' -> NAK, we do regular control sum
           char controlSum = (char) 0x00; // initializing control sum
           for (int i = 0; i < 128; i++)
               controlSum += data[i]; // adding values of each element of data block
           controlSum = controlSum % 256; // doing % 256 so that value is between 0-255
           ReadFile(const_handle, &sign, 1, &sizeOfSign,nullptr);
           if (controlSum != sign) { // if control sum is not equal to read sign then an error has occured
               cout << "Niepoprawna suma kontrolna.\n";
               WriteFile(const_handle, &NAK, 1, &sizeOfSign, nullptr);
               rightPackage = false;
           }
       }
        // if no errors have been found then we write recieved data to recieveTXT file
        if (rightPackage) {
            for (int i = 0; i < 128; i++) {
                if (data[i] != 26)
                    receiveTXT << data[i];
            }
            cout << "Odbieranie " << blockNumber << ". pakietu powiodlo sie.\n";
            WriteFile(const_handle, &ACK, 1, &sizeOfSign, nullptr);
        }
    }
    // is everything succeeded we send back ACK
    WriteFile(const_handle, &ACK, 1, &sizeOfSign, nullptr);

    // closing file and handle
    receiveTXT.close();
    CloseHandle(const_handle);

    if (sign == CAN) cout << "Polaczenie zostalo utracone.\n";
    else cout << "Plik zostal odebrany w calosci.\n";

    return 0;
}
