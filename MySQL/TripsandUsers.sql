declare a int
declare b int 
select t1.Request_at as Day,a/b as `Cancellation Rate`
from Trips t1
select count(t1.Request_at) into b
select count(t1.Request_at) into a where Status like "cancellde%"
where t1.Client_Id in (
    select Users_Id from Users where Banned="No" and Role="client"
)
group by t1.Request_at

-- select t1.Request_at as Day,format((select count(Status) from Trips t2 where t2.Request_at=t1.Request_at and Status like "cancellde%" and  t2.Client_Id in (
--     select Users_Id from Users where Banned="No" and Role="client"
-- ))/count(t1.Request_at)) as `Cancellation Rate`
-- from Trips t1
-- where t1.Client_Id in (
--     select Users_Id from Users where Banned="No" and Role="client"
-- )
-- group by t1.Request_at