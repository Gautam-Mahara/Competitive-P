def removeStr(s, st, memo):
    if len(s) == 0:
        return 0
    if s in memo:
        return memo[s]
    
    max_count = 0
    for i in st:
        pos = s.find(i)
        if pos != -1:  # If substring i is found in s
            modstring = s[:pos] + s[pos + len(i):]  # Remove the substring
            max_count = max(max_count, 1 + removeStr(modstring, st, memo))
    
    memo[s] = max_count
    return max_count

# Input
s = "helloworlds"
st = ["hd", "el", "llo", "wor", "ell", "lds"]
memo = {}

# Output the result
print(removeStr(s, st, memo))
