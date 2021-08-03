def display_hash(hashTable):
    for i in range(len(hashTable)):
        print(i, end=" ")

        for j in hashTable[i]:
            print("-->", end=" ")
            print(j, end=" ")

        print()


# Creating Hashtable as
# a nested list.


# Hashing Function to return
# key for every value.
def hashing(keyvalue):
    return keyvalue % len(hash_table)

def search(hashtable, keyvalue):
    hash_key = hashing(keyvalue)
    index = hashtable[hash_key]
    for index_list, record in enumerate(index):
        record_key = record
        if record_key == keyvalue:
            return True
            #return index
            break
# Insert Function to add
# values to the hash table
def delete(hashtable, keyvalue):
    if search(hashtable, keyvalue):
        hash_key = hashing(keyvalue)
        index = hashtable[hash_key]
        for index_list, record in enumerate(index):
            record_key = record
            if record_key == keyvalue:
                index.pop(index_list)
        #search(hashtable, keyvalue).pop(keyvalue)





def insert(hashtable, value):
    hash_key = hashing(value)
    hashtable[hash_key].append(value)


# Driver Cod
hash_size = int(input())
hash_table = [[] for _ in range(hash_size)]
theinput = input()
n = theinput.split()
map_n = map(int, n)

list_n = list(map_n)
list_n.pop()

for num in list_n:
    insert(hash_table, num)

num_search = int(input())
delete(hash_table, num_search)
#if search(hash_table, num_search):
#    print("Encontrado\n")
#    delete(hash_table, num_search)
#else:
#    print("Não encontrado\n")
display_hash(hash_table)
