

#*arg

def func(a, b):
    return a+b

def func(*args):
    sum = 0
    for a in args:
        sum += a
    return sum


sum = func(1,2,3,4)
print("result:" + str(sum))


####################################
#unpacking list into constructor

class Transaction:
    def __init__(self, name, time, amount, city):
        self.name = name
        self.time = time
        self.amount = amount
        self.city = city

    def __str__(self):
        return self.name + "-" + self.time + "-" + self.amount + "-" + self.city


tx = "alice,20,800,mtv"
fields = tx.split(",")
transaction = Transaction(*fields) #list into constructor arguments
print(transaction)

