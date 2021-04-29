import sys
import collections

species_dict = collections.defaultdict(int)
total_cnt = 0

while True:
    species_name = sys.stdin.readline().strip()
    if not species_name:
        break
    species_dict[species_name] += 1
    total_cnt += 1


sorted_species = sorted(species_dict.keys())

for species in sorted_species:
    print(f'{species} {species_dict[species]/total_cnt*100:.4f}')
