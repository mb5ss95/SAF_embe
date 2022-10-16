lst = ['m', 'bts', 'bts', 'mc', 'bts']

dic = {}
for i in lst:
    dic[i] = 0

for i in lst:
    dic[i] += 1

print(dic)
max_num = max(dic.values())
temp = {j:i for i, j in dic.items()}
print(temp.get(max_num))

