def main():
    n = int(input())
    nums = input()
    nums = nums.split(' ')
    for i in range(len(nums)):
        nums[i] = int(nums[i])
    pivots = []
    max = -2147483648
    for num in nums:
        for i in reversed(range(0, len(pivots))):
            if pivots[i] >= num:
                pivots.pop(i)
            else:
                break
                
        if num >= max:
            max = num
            pivots.append(num)
    print(len(pivots))
    

if __name__ == '__main__':
    main()