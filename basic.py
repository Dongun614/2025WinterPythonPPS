# 정수, 실수, 문자열
age = 25
height = 175.5
name = "Gemini"

numbers = [1,2,3,4,5]
print(numbers[0])

score = 85

if score >= 90:
    print("A")
elif score >= 80:
    print("B")
else:
    print("C")
    
for i in range(5):
    print(i)
    
fruits = ["사과", "바나나", "포도"]
for fruit in fruits:
    print(f"내가 좋아하는 과일은 {fruit}입니다.")
    
def add_numbers(a, b):
    return a + b

result = add_numbers(10, 20)
print(result)