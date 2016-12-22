select w1.Id 
from Weather w1,Weather w2
where w1.Temperature>w2.Temperature and datediff(w1.Date,w2.Date)=1