''''Consider telephone book data of N clients make use of hash table implementation to quickly look up clients telephone number'''

max = int(input("Enter max size: "))
print("MAx size entered is: ",max)

l = [0] * max
while(l):
    key = int(input("Enter telephone no.: "))
    hash_key = key % max
    print("Hash Key is = ",hash_key)
    
    if (l[hash_key] == 0):
        l[hash_key] = key
        
    else:
        l[hash_key + 1]  = key
    print("After inserting", l)