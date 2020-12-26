open = '('
close = ')'

str = input()
n = len(str)
bras = list(str)

p = 1
count = 0
stack_list = []
check = 0

for bra in bras:
    if bra == open:
        stack_list.append(count + 1)
        p += 1
        count += 1
    elif bra == close:
        if len(stack_list)!=0:
            p -= 1
            print('[%d,%d]'%(stack_list.pop(), count+1))
            count += 1
        else:
            check = 1
            count += 1
    else:
        print('[Letter Error]')
        break

if p!=1 or check==1:
    print('[Correspondence Error]')