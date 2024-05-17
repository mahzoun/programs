from pybulletproofs import zkrp_prove, zkrp_verify

proof1, comm1, _ = zkrp_prove(2022, 32)
proof2, comm2, _ = zkrp_prove(2023, 32)

print(bytes(proof1).hex(), "\n", comm1)
assert zkrp_verify(proof1, comm1)
assert zkrp_verify(proof2, comm1) == False