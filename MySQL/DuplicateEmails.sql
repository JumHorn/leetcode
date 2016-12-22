# Write your MySQL query statement below
select distinct Email
from Person p1
where exists (select Email from Person p2 where p1.Email=p2.Email and p1.Id!=p2.Id)