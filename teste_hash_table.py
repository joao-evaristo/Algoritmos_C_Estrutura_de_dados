class hash_table:
    def __init__(self, size_hash):
        self.size = size_hash
        self.hash_table = self.create_indexs

    def create_indexs(self):
        return [[] for _ in range(self.size)]

    def hashing(self, value):
        return value % self.size

    def insertion(self, value):
        key = self.hashing(value)
        self.create_indexs()

    def search(self):

    def delete(self):
