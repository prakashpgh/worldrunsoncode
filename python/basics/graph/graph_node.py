#graphs in classes
class Node:
    def __init__(self, val=0, neighbors = None):
        self._value = val
        self._neighbors = []

    def display(self):
        connections = [node._value for node in self._neighbors]
        str = f"{self._value} is connected to {connections}"
        return str
    
    def __str__(self):
        return self.display()

