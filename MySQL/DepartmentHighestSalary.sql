# Write your MySQL query statement below
select D1.Name as Department,E1.Name as Employee, E1.Salary as Salary
from Employee E1 inner join Department D1 on E1.DepartmentId=D1.Id
where E1.Salary in (select max(Salary) from Employee E2 where E1.DepartmentId=E2.DepartmentId)