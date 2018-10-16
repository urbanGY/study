x = c("Yes", "No", "No", "Yes", "Yes")
table(x)

x = c("Yes", "No", "No", "Yes", "Yes")
x
factor(x)

beer = scan()
3 4 1 1 3 4 3 3 1 3 2 1 2 1 2 3 2 3 1 1 1 1 4 3 1
barplot(beer)
barplot(table(beer))
barplot(table(beer)/length(beer))

table(beer)/length(beer)

beer.counts = table(beer)
pie(beer.counts)
names(beer.counts) = c("domestic\n can", "Domestic\n bottle", "Microbrew", "Import")
pie(beer.counts)
pie(beer.counts, col=c("purple", "green2", "cyan", "white"))

sals = scan()
12 .4 5 2 50 8 3 1 4 0.25
mean(sals)
var(sals)
sd(sals)
median(sals)
fivenum(sals)
summary(sals) #page15

data = c(10, 17, 18, 25, 28, 28)
summary(data)
quantile(data,.25)
quantile(data,c(.25,.75))

sort(sals)
fivenum(sals)
summary(sals)

mean(sals,trim=1/10)
mean(sals,trim=2/10)
IQR(sals)

mad(sals)
median(abs(sals-median(sals)))
median(abs(sals-median(sals)))*1.4826

scores = scan()
2 3 16 23 14 12 4 13 2 0 0 0 6 28 31 14 4 8 2 5
apropos("stem")
stem(scores)

stem(scores,scale=2)
sals = c(12, .4, 5, 2, 50, 8, 3, 1, 4, .25)
cats = cut(sals, breaks=c(0,1,5,max(sals)))
cats
table(cats)
levels(cats) = c("poor", "rich", "rolling in it")
table(cats)

x = scan()
29.6 28.2 19.6 13.7 13.0 7.8 3.4 2.0 1.9 1.0 0.7 0.4 0.4 0.3 0.3
0.3 0.3 0.3 0.2 0.2 0.2 0.1 0.1 0.1 0.1 0.1
hist(x)
hist(x,probability = TRUE)
rug(jitter(x))

hist(x,breaks=10)
hist(x,breaks = c(0,1,2,3,4,5,10,20,max(x)))

library("UsingR")
data(movies)
names(movies)
attach(movies)
boxplot(current, main="current receipts", horizontal = TRUE)
boxplot(gross, main="gross receipts", horizontal = TRUE)
detach(movies)

library("ts")
data("lynx")
summary(lynx)
x = c(.314, .289, .282, .279, .275, .267, .266, .265, .256, .250, .249, .211, .161)
tmp = hist(x)
lines(c(min(tmp$breaks),tmp$mids,max(tmp$breaks)),c(0,tmp$counts,0),type="l")

data(faithful)
attach(faithful)
hist(eruptions, 15, prob=T)
lines(density(eruptions))
lines(density(eruptions,bw="SJ"),col='red')

smokes = c("Y","N","N","Y","N","Y","Y","Y","N","Y")
amount = c(1,2,2,3,3,1,2,1,3,2)
table(smokes,amount)
tmp = table(smokes,amount)
old.digits = options("digits")
options(digits=3)
prop.table(tmp,1)
prop.table(tmp,2)
prop.table(tmp)
options(digits=old.digits)


barplot(table(smokes,amount))
barplot(table(amount,smokes))
somkes=factor(smokes)
barplot(table(smokes,amount),beside=TRUE,legend.texT=T)

barplot(table(amount,smokes),main="table(amount,smokes)",
        beside=TRUE,
        legend.text=c("less than 5","5-10","more than 10"))

#page28
prop = function(x) x/sum(x)
apply(x,2,prop)
t(apply(x,1,prop))
#don't work
x = c(5,5,5,13,7,11,11,9,8,9)
y = c(11,8,4,5,9,5,10,5,4,10)
boxplot(x,y)

amount = scan()
5 5 5 13 7 11 11 9 8 9 11 8 4 5 9 5 10 5 4 10
category = scan()
1 1 1  1 1  1  1 1 1 1  2 2 2 2 2 2  2 2 2  2
boxplot(amount ~ category)

library("UsingR");data(home)
attach(home)
names(home)
boxplot(scale(old),scale(new))
detach(home)

stripchart(scale(old),scale(new))
simple.violinplot(scale(old),scale(new))

data(home);attach(home)
plot(old,new)
detach(home)

#??
data(homedata)
attach(homedata)
plot(old,new)
detach(homedata)
#don't work

x = 1:2;y=c(2,4);df=data.frame(x=x, y=y)
ls()
rm(y)
attach(df)
ls()
ls(pos=2)
y
x
x=c(1,3)
df
detach(df)
x
y

data(home);attach(home)
x=old
y=new
plot(x,y)
abline(lm(y~x))
detach(home)

data(home);attach(home)
x=old; y=new
simple.lm(x,y)
detach(home)
lm.res = simple.lm(x,y)

coef(lm.res)
coef(lm.res)[1]
simple.lm(x,y,show.residuals=TRUE)

lm.res = simple.lm(x,y)
the.residuals = resid(lm.res)
plot(the.residuals)

cor(x,y)
cor(x,y)^2

rank(c(2,3,5,7,11))
rank(c(5,3,2,7,11))
rank(c(5,5,2,7,5))
cor(rank(x),rank(y))
cor.sp <- function(x,y) cor(rank(x), rank(y))
cor.sp(x,y)

data("florida")
names(florida)
attach(florida)
simple.lm(BUSH,BUCHANAN)

#here! page36 
detach(florida)
identify(BUSH,BUCHANAN,n=2)
BUSH[50]
BUCHANAN[50]
florida[50,]
simple.lm(BUSH[-50],BUCHANAN[-50])
65.57350 + 0.00348 * BUSH[50]

simple.lm(BUSH[-50],BUCHANAN[-50],pred=BUSH[50])

simple.lm(BUSH,BUCHANAN)
abline(65.57350,0.00348)

library(MASS)
attach(florida)
plot(BUSH,BUCHANAN)
abline(lm(BUCHANAN ~ BUSH,lty="1"))
abline(rlm(BUCHANAN ~ BUSH,lty="2"))
legend(locator(1),legend=c('lm','rlm'),(lty=1:2))
detach(florida)

plot(BUSH,BUCHANAN)
abline(rlm(BUCHANAN ~ BUSH,lty = '1'))
abline(rlm(BUCHANAN[-50] ~ BUSH[-50],lty = '2'))

x = seq(0,4,by=.1)
plot(x,x^2,type="l")
curve(x^2,0,4)

miles = (0:8)*4
tread = scan()
394 329 291 255 229 204 179 163 150
plot(miles,tread)
abline(360,-7.3)
points(miles,360 - 7.3*miles,type="l")
lines(miles,360 - 7.3*miles)
curve(360 - 7.3*x,add=T)

library('MASS')
data('UScereal')
attach(UScereal)
names(UScereal)#40 page

library("UsingR")
data("babies")
attach(babies)

weight = c(150,135,210,140)
height = c(65,61,70,65)
gender = c("Fe","Fe","M","Fe")
study = data.frame(weight,height,gender)
study

study = data.frame(w=weight,h=height,g=gender)##
row.names(study)<-c("Mary","Alice","Bob","Judy")
study
rm(weight)
weight
attach(study)
weight

study[,'weight']
study[,1]
study[,1:2]
study['Mary',]
study['Mary','weight']
study$weight
study[['weight']]
study[['w']]
study[[1]]
study[study$gender == 'Fe',]
data(PlantGrowth)
PlantGrowth
attach(PlantGrowth)
weight.ctrl = weight[group == "ctrl"]
unstack(PlantGrowth)
boxplot(unstack(PlantGrowth))
boxplot(weight ~ group)

library(MASS);data(Cars93);attach(Cars93)
price = cut(Price,c(0,12,20,max(Price)))
levels(price)=c("cheap","okay","expensive")
mpg = cut(MPG.highway,c(0,20,30,max(MPG.highway)))
levels(mpg) = c("gas guzzler","okay","miser")
table(Type)
table(price,Type)
table(price,Type,mpg)

barplot(table(price,Type),beside = T)
barplot(table(Type,price),beside = T)

y=rnorm(1000)
f=factor(rep(1:10,100))
boxplot(y~f,main="Boxplot of normal random data with model notation")
x = rnorm(100)
y = factor(rep(1:10,10))
stripchart(x ~ y)

par(mfrow=c(1,3))
data(InsectSprays)
boxplot(count ~ spray, data = InsectSprays, col="lightgray")
simple.violinplot(count ~ spray, data=InsectSprays, col="lightgray")
simple.densityplot(count ~ spray, data = InsectSprays)
plot(x,y)
points(x,y,pch="2")

data("ToothGrowth")
attach(ToothGrowth)
plot(len ~ dose,pch=as.numeric(supp))
tmp=levels(supp)
legend(locator(1), legend = tmp, pch=1:length(tmp))
datach(ToothGrowth)

data(emissions)
attach(emissions)
simple.scatterplot(perCapita,CO2)
title("GDP/capita vs c02 emissions 1999")
detach(emissions)
pairs(emissions)

histogram(~ Max.Price | Cylinders, data = Cars93)
bwplot(~ Max.Price | Cylinders, data= Cars93)

attach(Cars93)
xyplot(MPG.highway ~ Fuel.tank.capacity | Type)
plot.regression = function(x,y){
  panel.xyplot(x,y)
  panel.abline(lm(y~x))
}
trellis.device(bg="white")
xyplot(MPG.highway ~ Fuel.tank.capacity | Type, panel = plot.regression)

age.yr = cut(age,seq(0,144,by=12),labels=0:11)

sample(1:6,10,replace=T)
RollDie = function(n) sample(1:6,n,replace=T)
RollDie(5)

runif(1,0,2)
runif(5,0,2)
runif(5)

x = runif(100)
hist(x,probability = TRUE, col=gray(.9), main="uniform on [0,1")
curve(dunif(x,0,1),add=T)

rnorm(1,100,16)
rnorm(1,mean=280,sd=10)
x=rnorm(100)
hist(x,probability = TRUE, col=gray(.9),main="normal mu=0, sigma=1")
curve(dnorm(x),add=T)

n = 1
p = .5
rbinom(1,n,p)
rbinom(10,n,p)
n = 10; p = .5
rbinom(1,n,p)
rbinom(5,n,p)

n=5;p=.25
x=rbinom(100,n,p)
hist(x,probability = TRUE,)
xvals = 0:n; points(xvals,rbinom(xvals,n,p),type="h",lwd=3)
points(xvals,rbinom(xvals,n,p),type="p",lwd=3)

x=rexp(100,1/2500)
hist(x,probability = TRUE, col=gray(.9),main="exponential mean=2500")
curve(dexp(x,1/2500),add=T)

sample(1:6,10,replace = TRUE)
sample(c("H","T"),10,replace=TRUE)
sample(1:54,6)
cards = paste(rep(c("A",2:10,"J","Q","K"),4),c("H","D","S","C"))
sample(cards,5)
dice=as.vector(outer(1:6,1:6,paste))
sample(dice,5,replace=TRUE)

data(faithful)
names(faithful)
eruptions = faithful[['eruptions']]
sample(eruptions,10,replace = TRUE)
hist(eruptions,breaks=25)
hist(sample(eruptions,100,replace=TRUE),breaks=25)

pnorm(.7)
pnorm(.7,1,1)
pnorm(.7,lower.tail = F)
qnorm(.75)

x = rnorm(5,100,16)
x
z=(x-100)/16
z

pnorm(z)
pnorm(x,100,16)

rnorm(5,mean=0,sd=1:5)

n = 10; p = .25; S = rbinom(1,n,p)
(S - n*p)/sqrt(n*p*(1-p))

n = 10; p = .25; S = rbinom(100,n,p)
X = (S - n*p)/sqrt(n*p*(1-p))
hist(X,prob=T)

results = numeric(0)
for(i in 1:100){
  S = rbinom(1,n,p)
  results[i] = (S - n*p)/sqrt(n*p*(1-p))
}

primes = c(2,3,5,7,11);
for(i in 1:5) print(primes[i])
for(i in primes) print(i)

results = c();
mu = 0; sigma = 1
for(i in 1:200) {
  X = rnorm(100,mu,sigma)
  results[i] = (mean(X) - mu)/(sigma/sqrt(100))
}
hist(results,prob=T)

x = rnorm(100,0,1); qqnorm(x,main='normal(0,1');qqline(x)
x = rnorm(100,10,15); qqnorm(x,main='normal(10,15');qqline(x)
x = rexp(100,1/10);qqnorm(x,main='exponential mu=10');qqline(x)
x = runif(100,0,1);qqnorm(x,main='unif(0,1)');qqline(x)

f = function(){
  S = rbinom(1,n,p)
  (S - n*p)/sqrt(n*p*(1-p))
}

x = simple.sim(100,f)
hist(x)

f = function(n = 100, p = .5){
  S = rbinom(1,n,p)
  (S - n*p)/sqrt(n*p*(1-p))
}

simple.sim(1000,f,100,.5)
the.range = function(x) max(x) - min(x)
find.IQR = function(x){
  five.num = fivenum(x)
  five.num[4] - five.num[2]
}

x = rnorm(100)
find.IQR
function(x) {
  five.num = fivenum(x)
  five.num[4] - five.num[2]
}
find.IQR(x)

f = function(n=100,mu=0,sigma=1){
  nos = rnorm(n,mu,sigma)
  (mean(nos)-mu)/(sigma/sqrt(n))
}

simulations = simple.sim(100,f,100,5,5)
hist(simulations,breaks=10,prob=TRUE)

f = function(n = 100,mu = 10) (mean(rexp(n,1/mu))-mu)/(mu/sqrt(n))
xvals = seq(-3,3,.01)
hist(simple.sim(100,f,1,10),probability = TRUE,main="n=1",col=gray(.95))
points(xvals,dnorm(xvals,0,1),type="l")

k=1;sigma=1
n=length(x)
sum(-k*sigma<x&x<k*sigma)/n

f = function(n,a=0,b=1){
  mu=(b+a)/2
  sigma=(b-a)/sqrt(12)
  (mean(runif(n,a,b))-mu)/(sigma/sqrt(n))
}

for(n in 1:50){
  results = c()
  mu = 10; sigma= mu
  for(i in 1:200){
    X = rexp(200,1/mu)
    results[i] = (mean(X)-mu)/(sigma/sqrt(n))
  }
  hist(results)
  Sys.sleep(.1)
}

rt(100,4)
rt(100,50)
rchisq(100,4)
rchisq(100,50)

bootstrap = function(data,n=length(data)){
  boot.sample=sample(data,n,replace=TRUE)
  median(boot.sample)
}

simple.sim(100,bootstrap,faithful[['eruptions']])
res.median=c();res.mean=c()
for(i in 1:200){
  X = rnorm(200,0,1)
  res.median[i] = median(X);res.mean[i] = mean(X)
}
boxplot(res.mean,res.median)

##page70

data(homedata)
attach(homedata)
hist(y1970);hist(y2000)
detach(homedata)

attach(homedata)
simple.eda(y1970);simple.eda(y2000)
detach(homedata)

data(exec.pay)
simple.eda(exec.pay)
log.exec.pay = log(exec.pay[exec.pay > 0])/log(10)
simple.eda(log.exec.pay)

data(ewr)
names(ewr)
airnames = names(ewr)
ewr.actual = ewr[,3:10]
boxplot(ewr.actual)

par(mfrow=c(2,4))
attach(ewr)
for(i in 3:10) boxplot(ewr[,i] ~ as.factor(inorout),main=airnames[i])
detach(ewr)
par(mfrow=c(1,1))

X = runif(100);boxplot(X,horizontal = T,bty=n)
X = rnorm(100);boxplot(X,horizontal = T,bty=n)
X = rt(100,2);boxplot(X,horizontal = T,bty=n)

X = sample(1:6,100,p=7-(1:6),replace = T);boxplot(X,horizontal = T,bty=n)
X = abs(rnorm(200));boxplot(X,horizontal = T,bty = n)
X = rexp(200);boxplot(X,horizontal = T,bty=n)


alpha = c(0.2,0.1,0.05,0.001)
zstar = qnorm(1-alpha/2)
zstar

2*(1-pnorm(zstar))

m = 50; n = 20; p = .5;
phat = rbinom(m,n,p)/n
SE = sqrt(phat*(1-phat)/n)
alpha = 0.10;zstar = qnorm(1-alpha/2)
matplot(rbind(phat - zstar*SE, phat + zstar*SE),
        rbind(1:m,1:m), type="l", lty=1)
abline(v=p)

prop.test(42,100)
prop.test(42,100,conf.level = 0.90)

simple.z.test = function(x,sigma,conf.level=0.95){
  n=length(x);xbar=mean(x)
  alpha = 1-conf.level
  zstar = qnorm(1-alpha/2)
  SE = sigma/sqrt(n)
  xbar + c(-zstar*SE,zstar*SE)
}

simple.z.test(x,1.5)

t.test(x)

x=rnorm(100);y=rt(100,9)
boxplot(x,y)
qqnorm(x);qqline(x)
qqnorm(y);qqline(y)

xvals=seq(-4,4,.01)
plot(xvals,dnorm(xvals),type="l")
for(i in c(2,5,10,20,50)) points(xvals,dt(xvals,df=i),type="l",lty=i)
x = c(110,12,2.5,98,1017,540,54,4.3,150,432)
wilcox.test(x,conf.int=TRUE)



prop.test(42,100,p=.5)
prop.test(420,1000,p=.5)
xbar=22;s=1.5;n=10
t=(xbar-25)/(s/sqrt(n))
t

pt(t,df=n-1)

x = c(12.8,3.5,2.9,9.4,8.7,.7,.2,2.8,1.9,2.8,3.1,15.8)
stem(x)

wilcox.test(x,mu=5,alt="greater")
x = c(12.8,3.5,2.9,9.4,8.7,.7,.2,2.8,1.9,2.8,3.1,15.8)
simple.median.test(x,median=5)
simple.median.test(x,median=10)

prop.test(c(45,56),c(45+35,56+47))
x = c(15,10,13,7,9,8,21,9,14,8)
y = c(15,14,12,8,14,7,16,10,15,12)
t.test(x,y,alt="less",var.equal = TRUE)

t.test(x,y,alt="less")

x = c(3,0,5,2,5,5,5,4,4,5)
y = c(2,1,4,1,4,3,3,2,3,5)
t.test(x,y,paired=TRUE)

t.test(x,y)

data(ewr)
attach(ewr)
tmp = subset(ewr,inorout == "out", select=c("AA","NW"))
x = tmp[['AA']]
y = tmp[['NW']]
boxplot(x,y)

x = rchisq(100,5);y = rchisq(100,50)
simple.eda(x);simple.eda(y)

freq = c(22,21,22,27,22,36)
probs = c(1,1,1,1,1,1)/6
chisq.test(freq,p=probs)

x = c(100,110,80,55,14)
probs = c(29,21,17,17,16)/100
chisq.test(x,p=probs)

yesbelt = c(12813,647,359,42)
nobelt = c(65963,4000,2642,303)
chisq.test(data.frame(yesbelt,nobelt))

die.fair = sample(1:6,200,p=c(1,1,1,1,1,1)/6, replace = T)
die.bias = sample(1:6,100,p=c(.5,.5,1,1,1,2)/6, replace = T)
res.fair = table(die.fair);res.bias = table(die.bias)
rbind(res.fair,res.bias)

chisq.test(rbind(res.fair,res.bias))

chisq.test(rbind(res.fair,res.bias))[['exp']]





