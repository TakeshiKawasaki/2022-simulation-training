#install.packages("tidyverse",repos = "http://cran.us.r-project.org")
library(tidyverse)
input <- read.csv('stdin')

g <- ggplot(NULL) +
geom_point(data=input,aes(x=n,y=sqrt((data-pi)^2)),size = 3.0 ,colour = "white", shape = 4) +
scale_x_log10() +
scale_y_log10() +
stat_function(fun=function(x) y=sqrt(3.14159265358979323846/x),colour = "lightgreen") +
theme_minimal() +
labs(title = "Q1-3",x = "n",y = "error",size = 24,colour = "white") +
theme(text = element_text(size = 24,colour = "white")) +
theme(panel.background = element_rect(fill = "black")) +
theme(plot.background = element_rect(fill = "black")) +
theme(axis.text=element_text(colour = "white"))
ggsave(file = "./Q1-3.png", plot = g)

