# Input how many processes
n=int(input("How many processes:"))

# Completion time
CT = 0
TA = 0
WT = 0
sum = 0
CTA = []
ATA = [] 
TAA = []
WTA = []

print("Enter arrival time")
at = list(map(int,input().strip().split(" ")))[:n]
print("Enter burst time")
bt = list(map(int,input().strip().split(" ")))[:n]


# Append all completion time into array
for i in bt:
    CT = CT + i
    CTA.append(CT)

for i in range(n):
    WT = CTA[i]- (at[i] + bt[i]) 
    WTA.append(WT)
for i in WTA:
    sum = sum +i


print("Waiting time",WTA)
print("Average waiting time:",sum/n)

# for i in range(n):
#     TA = WTA[i] + bt[i]
#     TAA.append(TA)

# print("Completion time",CTA)
# print("Turn Around time",TAA)