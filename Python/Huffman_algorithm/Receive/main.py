import socket  # Importing the socket library
import Huffman  # Importing the Huffman module

# Creating a socket object
serverSocket = socket.socket()

# Specifying the IP address and port number for the socket to use
ip = "127.0.0.1"
port = 3554

# Set socket option to reuse address
serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# Binding the socket to the specified IP address and port number
serverSocket.bind((ip, port))
print("Socket bound with address:", ip, ":", port)

# Listening for incoming connections
serverSocket.listen()

# Continuously wait for connections and receive data
while True:
    text = ''
    # Accepting a connection request and returning a tuple
    (clientConnection, clientAddress) = serverSocket.accept()

    # Receiving data from the client
    while True:
        data = clientConnection.recv(1024).decode()
        if data == "END":
            # If the end of the message is reached, send a response and close the connection
            msg = "Server's answer:\nTransfer successful, ending connection..."
            msgBytes = str.encode(msg)
            clientConnection.send(msgBytes)
            print("\nConnection closed.\n")
            break
        text += data

    # Decoding the received data using the Huffman tree
    server = Huffman.decoding(text)
    print(server)

    # Writing the decoded data to a file
    filename = 'server.txt'
    file = open("server.txt", "w")
    file.write(server)
    file.close()
    break
