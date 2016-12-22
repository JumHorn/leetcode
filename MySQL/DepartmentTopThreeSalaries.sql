# Write your MySQL query statement below
select D1.Name as Department,E1.Name as Employee, E1.Salary as Salary
from Employee E1 inner join Department D1 on E1.DepartmentId=D1.Id
where E1.Salary >= (select min(Salary) from Employee E2 where E2.DepartmentId=1 order by E2.Salary desc limit 0,3;)

-- [1 "Joe" 60000 1]
-- [2 "Ralph" 30000 1]
-- [3 "Joel" 50000 1]
-- [4 "Tracy" 55000 1]
-- "Department": 
-- [1 "IT"]