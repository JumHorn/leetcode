# Write your MySQL query statement below
select s1.Score, (select count(distinct s2.Score)+1 from Scores s2 where s2.Score > s1.Score) as Rank
from Scores s1,Scores s2
order by Score desc