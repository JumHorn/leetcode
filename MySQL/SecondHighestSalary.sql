use LeetCode;
set @max_salary=(select max(salary) from Employee);

select distinct salary 
from Employee
where salary<@max_salary
order by salary desc
limit 0,1


