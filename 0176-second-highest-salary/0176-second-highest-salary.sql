# Write your MySQL query statement below
Select 
 max(salary) as SecondHighestSalary
FROM Employee
WHERE salary < (Select max(salary) FROM Employee)