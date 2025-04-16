'''
https://leetcode.com/problems/minimum-genetic-mutation/
'''
from collections import deque

def gene_mutation_bank(start_gene: str, end_gene: str, bank: list[str]) -> int:
    q = deque()
    q.append((start_gene, 0))
    visited = set()
    visited.add(start_gene)
    found = False
    while q:
        gene, hops = q.popleft()
        if gene == end_gene:
            found = True
            return hops
        acgt = "ACGT"
        for ch in acgt:
            for i in range(len(gene)):
                next = gene[:i] + ch + gene[i+1:]
                print("gene: " + next)
                if next not in visited and next in bank:
                    q.append((next, hops+1))
                    visited.add(next)
    if not found:
        return -1


startGene = "AACCGGTT"
endGene = "AACCGGTA"
bank = ["AACCGGTA"]
result = gene_mutation_bank(startGene, endGene, bank)
print("result:" + str(result))
#1



startGene = "AACCGGTT"
endGene = "AAACGGTA"
bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
#Output: 2
result = gene_mutation_bank(startGene, endGene, bank)
print("result:" + str(result))
