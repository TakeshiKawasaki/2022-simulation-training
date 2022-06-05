#install.packages("tidyverse",repos = "http://cran.us.r-project.org")
library(tidyverse)
input <- read.csv('stdin')

g <- ggplot(NULL) +
geom_point(data=input,aes(x=T,y=X2),size = 0.4 ,colour = "magenta", shape = 4) +
geom_point(data=input,aes(x=T,y=X3),size = 0.4 ,colour = "yellow", shape = 4) +
geom_point(data=input,aes(x=T,y=X1),size = 0.4 ,colour = "cyan", shape = 4) +
theme_minimal() +
labs(title = "Q2-4",x = "t/t0",y ="X(t)/a" ,size = 16,colour = "white") +
theme(text = element_text(size = 24,colour = "white")) +
theme(panel.background = element_rect(fill = "black")) +
theme(plot.background = element_rect(fill = "black")) +
theme(axis.text=element_text(colour = "white")) +
annotate("text", x=5.5, y=0.38,label="t0/td=1",colour="cyan",size=7) +#参考:https://mukkujohn.hatenablog.com/entry/2016/09/28/223957
annotate("text", x=5.5, y=0.28,label="t0/td=2",colour="magenta",size=7) +
annotate("text", x=5.5, y=0.18,label="t0/td=3",colour="yellow",size=7) 
ggsave(file = "./Q2-4.png", plot = g)

 
