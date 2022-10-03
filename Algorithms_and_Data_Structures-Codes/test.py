import sys

lines=[]
while True:
    line=sys.stdin.readline().strip()
    if not line:
        break
    lines.append(line)
print(lines)