# Write your MySQL query statement below
Select 
   email
FROM Person
group by email having count(email) > 1
