'''

'''

def create_hello_world_function():
    def f(*args):
        return "Hello World"
    return f


f = create_hello_world_function()
print(f())

