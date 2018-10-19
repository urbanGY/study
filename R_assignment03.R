x = c(18,23,25,35,65,54,34,56,72,19,23,42,18,39,37)
y = c(202,186,187,180,156,169,174,172,153,199,193,174,198,183,178)
plot(x,y)
abline(lm(y ~ x))
lm(y ~ x) 

lm.result=simple.lm(x,y)
summary(lm.result)

coef(lm.reslut)
lm.res = resid(lm.result)
summary(lm.res)

plot(lm.result)

es = resid(lm.result)
b1= (coef(lm.result))[['x']]
s = sqrt(sum(es^2)/(n-2))
SE = s/sqrt(sum((x-mean(x))^2))
t = (b1 - (-1))/SE
pt(t,13,lower.tail=FALSE)

SE = s*sqrt(sum(x^2)/(n*sum(x-mean(x))^2))
b0 = 210.04846
t = (b0-220)/SE
pt(t,13,lower.tail=TRUE)

simple.lm(x,y,show.ci=TRUE,conf.level=0.90)

lm.result = lm(y~x)
summary(lm.result)
plot(x,y)
abline(lm.result)

resid(lm.result)
coef(lm.result)
coef(lm.result)[1]
coef(lm.result)['x']

fitted(lm.result)
coefficients(lm.result)
coefficients(summary(lm.result))
coefficients(summary(lm.result))[2,2]
coefficients(summary(lm.result))['x','Std. Error']

predict(lm.result,data.frame(x=c(50,60)))
predict(lm.result,data.frame(x=sort(x)),
        level=.9, interval="confidence")

plot(x,y)
abline(lm.result)
ci.lwr = predict(lm.result, data.frame(x=sort(x)),
        level=.9, interval="confidence")[,2]

points(sort(x),ci.lwr,type="l")

curve(predict(lm.result,data.frame(x=x),
              interval="confidence")[,3],add=T)

x = 1:10
y = sample(1:100,10)
z = x+y
lm(z ~ x+y)

z = x+y + rnorm(10,0,2)
lm(z ~ x+y)

z = x+y + rnorm(10,0,10)
lm(z ~ x+y)

lm(z ~ x+y -1)
summary(lm(z ~ x+y))

library(lattice);data(homeprice);attach(homeprice)
panel.lm = function(x, y){
  panel.xyplot(x,y)
  panel.abline(lm(y~x))}

xyplot(sale ~ rooms | neighborhood,panel= panel.lm,data=homeprice)
nbd = as.numeric(cut(neighborhood,c(0,2,3,5),labels=c(1,2,3)))
table(nbd)

xyplot(sale ~ rooms | nbd, panel = panel.lm,layout=c(3,1))

summary(lm(sale ~ bedrooms + nbd))
-58.9 + 115.32*(1:3)
summary(lm(sale ~ bedrooms + nbd + full))

SE = 18.19
t = (28.51 - 15)/SE
t
pt(t,df=25,lower.tail=F)

dist = c(253,337,395,451,495,534,574)
height = c(100,200,300,450,600,800,1000)
lm.2 = lm(dist ~ height + I(height^2))
lm.3 = lm(dist ~ height + I(height^2) + I(height^3))
lm.2
lm.3

quad.fit = 200.211950 + .706182 * pts -0.000341 * pts^2
cube.fit = 155.5 + 1.119 * pts - .001234 * pts^2 + 0.00000555 * pts^3
plot(height,dist)
lines(pts,quad.fit,lty=1,col="blue")
lines(pts,quad.fit,lty=2,col="red")
legend(locator(1),c("quadratic fit", "cubic fit"),lty = 1:2, col=c("blue","red"))

summary(lm.3)
pts = seq(min(height),max(height),length=100)
makecube = sapply(pts,function(x) coef(lm.3) %*% x^(0:3))
makesquare = sapply(pts,function(x) coef(lm.2) %*% x^(0:3))
lines(pts,makecube,lty=1)
lines(pts,makesquare,lty=2)

x = c(4,3,4,5,2,3,4,5)
y = c(4,4,5,5,4,5,4,4)
z = c(3,4,2,4,5,5,4,4)
scores = data.frame(x,y,z)
boxplot(scores)

scores = stack(scores)
names(scores)
oneway.test(values ~ ind, data=scores, var.equal = T)

df = stack(data.frame(x,y,z))
oneway.test(values ~ ind, data=df, var.equal = T)
anova(lm(values ~ ind, data=df))





