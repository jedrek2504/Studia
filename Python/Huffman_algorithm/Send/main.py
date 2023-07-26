import socket  # import socket module to establish socket connections
import Huffman  # import Huffman module to use the Huffman coding/decoding functions
from os.path import getsize  # import getsize from os.path module to get the size of a file in bytes

# create a client socket object
clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# define the IP address and port number of the server we want to connect to
ip = "127.0.0.1"
port = 3554

# connect the client socket to the server
clientSocket.connect((ip, port))
print("Socket connected with address:", ip, ":", port)


# define a function to split a message into fixed-size chunks
def data_packages(data, n):
    chunks = [data[i:i + n] for i in range(0, len(data), n)]
    return chunks


# open the file containing the message to be sent
file = open("message.txt", "r")

# initialize some variables
DATA_SIZE = ''
data = ''

# read the file line by line and store its contents in a variable
for line in file:
    DATA_SIZE = data  # store the data size before Huffman coding
    data += line  # concatenate the lines of the file

# split the message into fixed-size chunks
chunked = (list(data_packages(data, 128)))

# send each chunk of the message to the server
for i in range(len(chunked)):
    package = Huffman.coding(chunked[i]).encode("ascii")  # Huffman code the chunk
    clientSocket.send(package)  # send the Huffman-coded chunk to the server
    print('sent package, number:', i + 1, )

# send an "END" message to the server to signal the end of the transmission
clientSocket.send("END".encode("ascii"))

# receive the response from the server
dataFromServer = clientSocket.recv(1024).decode("ascii")

# print the response from the server
print(dataFromServer)

# get the size of the file before Huffman coding and the size of the transmitted data
filename = 'message.txt'
size_sent = round(len(DATA_SIZE) / 1024, 2)
FILE_SIZE = round(getsize(filename) / 1024, 2)

# calculate the percentage of compression achieved
compression = round((1 - size_sent / FILE_SIZE) * 100, 2)

# print some statistics about the transmission
print("Size of transmitted data:        {}kB".format(size_sent))
print("Size of file before compression: {}kB".format(FILE_SIZE))
print("Percentage of compression:       {}%".format(compression))
