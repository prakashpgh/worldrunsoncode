#graphs in classes
class Node:
    def __init__(self, val=0, neighbors = None):
        self.value = val
        self._neighbors = []

    def display(self):
        connections = [node.value for node in self._neighbors]
        str = f"{self.value} is connected to {connections}"
        return str
    
    def __str__(self):
        return self.display()

