select Id 
from Weather w1
where w1.Temperature>(select Temperature from Weather w2 where datediff(w1.Date,w2.Date)=1)