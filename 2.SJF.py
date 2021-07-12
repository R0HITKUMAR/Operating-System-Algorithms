at1=[]
bt1=[]
at=[]
bt=[]
atT=[0,1,4,6,8]
btT=[4,2,1,4,2]
ref=atT.copy()
at1.append(min(atT))
bt1.append(btT[atT.index(min(atT))])
atT.remove(min(atT))
btT.remove(btT[atT.index(min(atT))])
while len(atT)!=0:
    bt1.append(min(btT))
    at1.append( atT[btT.index(min(btT))] )
    atT.remove(atT[btT.index(min(btT))])
    btT.remove(min(btT))
t=0
i=1
tempS=[]
for i in range(len(at1)):
    if at1[i]<=t:
        at.append(at1[i])
        bt.append(bt1[i])
        t+=bt1[i]
    else:
        tempS.append(i)
for i in tempS:
    at.append(at1[i])
    bt.append(bt1[i])

cf=[]
tat=[]
wt=[]

cf.append(at[0]+bt[0])
for i in range(1,len(at)):
    if at[i]>cf[i-1]:
        cf.append(at[i]+bt[i])
    else:
        cf.append(cf[i-1]+bt[i])
for i in range(len(at)):
    tat.append(cf[i]-at[i])
    wt.append(tat[i]-bt[i])

print(" AT BT WT TAT")
for i in range(len(at)):
    print("P"+str((ref.index(at[i]))+1),at[i],bt[i],wt[i],tat[i],sep=" ")
print("AVERAGE WAIT TIME "+str(sum(wt)/len(wt))+" UNITS")
print("AVERAGE TURN AROUND TIME "+str(sum(tat)/len(tat))+" UNITS")
