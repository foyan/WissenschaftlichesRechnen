import sys
import math

if __name__ == '__main__':
    
    class Node:
        def __init__(self, char):
            self.char = char
            self.freq = 0
            self.parent = None
            self.children = []
            self.index = 0
            self.code = ""
            self.level = 0
    
    maxChildren = min(max(int(sys.argv[2]), 2), 5)

    content = open(sys.argv[1]).read()
          
    freq = dict()
    length = 0
    
    """ analyze frequency """
    for c in content:
        if c not in freq:
            freq[c] = Node(c)
        freq[c].freq += 1
        length += 1
        
    """ build tree """
    nodes = list(freq.values())
    
    while len(nodes) > 1:
        nodes.sort(key = lambda node: node.freq)
        intermediate = Node("")
        for i in range(0, min(maxChildren, len(nodes))):
            node = nodes.pop(0)
            node.parent = intermediate
            node.index = i
            intermediate.children.append(node)
            intermediate.freq += node.freq
            intermediate.char += "/" + node.char
        nodes.append(intermediate)
        
    def traverse(node, codebook):
        if len(node.children) == 0:
            codebook[node.char] = node
        for ch in node.children:
            ch.code = node.code + bin(ch.index)[2:].zfill(math.ceil(math.log(maxChildren, 2)))
            ch.level = node.level + 1
            traverse(ch, codebook)
        
    codebook = dict()
    traverse(nodes[0], codebook)

    """for node in sorted(codebook.values(), key = lambda n: length - n.freq):
        print("char: '" + node.char + "', freq: " + str(node.freq) + ", code: " + node.code)"""
    
    entropy = 0.0
    for f in freq:
        entropy += freq[f].freq / length * math.log(length / freq[f].freq, 2)
    print("entropy: " + str(entropy))
    
    encodedLength = 0
    for ch in content:
        encodedLength += len(codebook[ch].code)
        
    print("input length: " + str(length) + "; output length: " + str(encodedLength/8) + " => ratio: " + str(encodedLength/8/length))
    
    longestCode = sorted(codebook.values(), key = lambda n: -n.level)[0]
    print("tree depth: " + str(longestCode.level) + "; code length: " + str(len(longestCode.code)))
    
    pass