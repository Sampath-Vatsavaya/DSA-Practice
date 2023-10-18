
def insertion_sort(arr):
    for i in range(1,len(arr)):
        anchor=arr[i]
        j=i-1
        while j>=0 and anchor<arr[j]:
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=anchor
        k=j+1
        if(k//2)!=0:
            print(arr[k//2])
        else:
            print((arr[k//2]+arr[k//2+1])/2)
            
    




if __name__ == '__main__':
    elements=[2, 1, 5, 7, 2, 0, 5]
    insertion_sort(elements)
    print(elements)
    