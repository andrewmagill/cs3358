class Queue(object):
    def __init__(self, max=8):
        self.max = max + 1
        self.read = self.max - 1
        self.write = self.max - 1
        self.items = [None] * self.max

    def enqueue(self, item):
        #if self.is_full():
        if self.alt_is_full():
            return False

        self.items[self.write] = item
        self.write = (self.write + 1) % self.max

        self.show()

        return True

    def dequeue(self):
        #if self.is_empty():
        if self.alt_is_empty():
            return None

        value = self.items[self.read]
        self.items[self.read] = None
        self.read = (self.read + 1) % self.max

        return value

    def is_empty(self):
        if self.read == self.write:
            if self.items[self.read] == None:
                return True
        return False

    def is_full(self):
        if self.read == self.write:
            if not self.items[self.read] == None:
                return True
            else:
                return False
        return False

    def size(self):
        size = None

        if self.read <= self.write:
            size = self.write - self.read
        elif self.read > self.write:
            size = self.write + self.max - self.read

        return size


    def alt_is_empty(self):
        return size == 0

    def alt_is_full(self):
        # this is the reason for max + 1
        # in dr. priebe's partial implementation
        # if the current size is one less than
        # the max, just call it full, that way
        # front index == rear index is if the
        # circular array is empty.
        return (self.size() + 1) == self.max

    def alt_is_empty(self):
        return self.size() == 0

    def __str__(self):
        str = ""
        count = self.read

        while not self.items[count] == None:
            str += "{0} ".format(self.items[count])
            count = (count + 1) % self.max
            if count == self.write:
                if self.is_full():
                    break

        return str

    def show(self):
        print "{0}\tread: {1}, write: {2}, e: {3}, f: {4}, s: {5}".format( \
                    self.items, \
                    self.read, self.write, \
                    self.alt_is_empty(), \
                    self.alt_is_full(), \
                    self.size())

q = Queue()

q.show()

for k in range(11):
    if q.enqueue(k):
        print "queueing? {0}".format(k)
    else:
        print "must be full, not queueing {0}".format(k)

print q

q.show()

for k in range(11):
    item = q.dequeue()
    if item:
        print "dequeue {0}".format(item)
    else:
        print "must be empty"

print q

q.show()

q.enqueue(55)
q.show()
q.enqueue(33)
q.show()
q.enqueue(22)
q.show()
q.enqueue(11)
q.show()
print q.dequeue()
q.show()
print q.dequeue()
q.show()
q.enqueue(99)
q.show()
