class Node:
    # constructor for Node
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq  # frequency of the character
        self.symbol = symbol  # the character itself
        self.left = left  # reference to the left child
        self.right = right  # reference to the right child
        self.huff = ''  # the Huffman code for the character


def createNodes(node, arr1, arr2, val=''):
    """
    Recursively create nodes and assign Huffman codes to each leaf node.

    node: Node - the current node being processed
    arr1: list - a list to store symbols
    arr2: list - a list to store Huffman codes
    val: str - the Huffman code assigned to the node
    """
    newVal = val + str(node.huff)

    # Recursively process the left child node, if it exists
    if node.left:
        createNodes(node.left, arr1, arr2, newVal)

    # Recursively process the right child node, if it exists
    if node.right:
        createNodes(node.right, arr1, arr2, newVal)

    # If the node is a leaf node, append its symbol and Huffman code to the respective lists
    if not node.left and not node.right:
        arr1.append(node.symbol)
        arr2.append(newVal)


def coding(msg):
    """
    Encode a message using the Huffman tree.

    msg: str - the message to be encoded
    """
    nodes = Huffman()  # build the Huffman tree
    letters = []  # list to store the symbols (letters) in the message
    code = []  # list to store the corresponding Huffman codes for each symbol

    # Call the createNodes function to fill the letters and code lists with the symbols and their Huffman codes
    createNodes(nodes[0], letters, code)

    output = ''  # string to store the encoded message
    for i in msg:
        # Look for the index of the symbol in the letters list and append its corresponding Huffman code to the
        # output string
        for j in range(len(letters)):
            if i == letters[j]:
                output = output + code[j]
    return output


def decoding(msg):
    """
    Decode a message using the Huffman tree.

    msg: str - the message to be decoded
    """
    nodes = Huffman()  # get the root node of the Huffman tree
    current_node = nodes[0]  # start from the root node
    output = ''
    for i in msg:  # loop through each binary digit in the message
        if int(i) == 0:  # if the digit is 0, go to the left child of the current node
            current_node = current_node.left
        else:  # if the digit is 1, go to the right child of the current node
            current_node = current_node.right
        if current_node.left is None and current_node.right is None:  # if the current node is a leaf node
            output += current_node.symbol  # add the symbol of the leaf node to the output string
            current_node = nodes[0]  # reset the current node to the root node
    return output


def Huffman():
    """
       Build a Huffman tree.

       Returns: Node - the root node of the Huffman tree
    """
    # Define list of characters
    chars = [
             'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
             'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
             'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
             'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
             'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
             'Y', 'Z', '-', '_', '/', '"', "'", ':', ';', ')',
             '(', '!', '.', '?', ',', chr(10), ' ', '1', '2', '3',
             '4', '5', '6', '7', '8', '9', '0', '=', '@', '*'
            ]

    # Define the frequency of characters
    freq = [
             87, 10, 29, 47,133, 25, 37, 84, 43, 1 ,
             5 , 55, 15, 97,107, 24, 2 , 73, 53, 85,
             49, 8 , 14, 1 , 32, 0 , 0 , 0 , 5 , 0 ,
             0 , 1 , 0 , 10, 1 , 0 , 8 , 0 , 3 , 0 ,
             6 , 6 , 0 , 1 , 1 , 19, 0 , 0 , 2 , 0 ,
             1 , 0 , 2 , 0 , 0 , 0 , 13, 0 , 0 , 1 ,
             1 , 10, 24, 0 , 39, 0 ,265, 0 , 0 , 0 ,
             0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
            ]

    # Create a list of Nodes for each character with its respective frequency
    nodes = []
    for x in range(len(chars)):
        nodes.append(Node(freq[x], chars[x]))

    # Continue building the Huffman tree until only one root node remains
    while len(nodes) > 1:
        # Sort the list of nodes by their frequency
        nodes = sorted(nodes, key=lambda x: x.freq)
        left = nodes[0]  # Get the left node
        right = nodes[1]  # Get the right node

        # Assign 0 to left node and 1 to right node
        left.huff = 0
        right.huff = 1

        # Create a new node with the sum of frequencies of left and right nodes
        # and concatenate the symbols of left and right nodes
        newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)

        # Remove the left and right nodes from the list
        nodes.remove(left)
        nodes.remove(right)

        # Add the new node to the list of nodes
        nodes.append(newNode)

    # Return the root node of the Huffman tree
    return nodes
