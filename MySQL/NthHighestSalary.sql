CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
      declare a int;
      declare m int;
      set a=N-1;
      if N=0 then set m=NULL;
      else
      select distinct Salary into m
      from Employee
      order by Salary desc
      limit a,1;
      end if;
  RETURN m;
END