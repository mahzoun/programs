import hashlib
message = "Hello, Quantstamp!"
hash_value = hashlib.sha256(message.encode()).hexdigest()
print(f"hash of message \n{message} is\n{hash_value}")