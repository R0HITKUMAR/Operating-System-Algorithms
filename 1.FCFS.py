at1=[6,4,2,8,15] 
bt1=[1,3,2,1,3]
at=[] 
bt=[] 
at=at1.copy() 
at. sort() 
for i in range(len(at)): 
    r= at.index(at[i]) 
    bt.append(bt1[r]) 
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
print("\tAT\tST\tWT\tTAT") 
for i in range(len(at)): 
    print("P"+str(i+1),at[i],bt[i],wt[i],tat[i],sep="\t") 
print("Average Wait time ="+str(round(sum(wt) / len(wt), 2))+" unit") 
print("Average Turn Around time ="+str(round(sum(tat) / len(tat), 2))+" unit") 
