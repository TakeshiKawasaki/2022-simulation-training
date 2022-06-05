#install.packages("tidyverse",repos = "http://cran.us.r-project.org")
library(tidyverse)
input <- read.csv('stdin')

ybreaks <- c(3.00,3.05,3.10,3.15,3.20,3.25,3.30)
g <- ggplot(NULL) +
geom_point(data=input,aes(x=n,y=data),size = 3.0 ,colour = "white", shape = 4) +
scale_x_log10() +
scale_y_continuous(breaks=ybreaks,labels= ybreaks,) +
#stat_function(fun=function(y) y=3.14159265358979323846,colour = "lightgreen") +
theme_minimal() +
labs(title = "Q1-2",x = "n",y = "output",size = 24,colour = "white") +
theme(text = element_text(size = 24,colour = "white")) +
theme(panel.background = element_rect(fill = "black")) +
theme(plot.background = element_rect(fill = "black")) +
theme(axis.text=element_text(colour = "white"))
ggsave(file = "./Q1-2.png", plot = g)

