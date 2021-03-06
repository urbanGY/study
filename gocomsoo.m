%% *기름 값, 오를땐 LTE 내릴땐 거북이... 범인은 누구?*
% *원유의 등락과 동떨어진 기름값의 흐름을 주위에서 종종 볼 수 있다. 
% 2009 - 2018 기간동안의 원유 값(두바이), 싱가폴 정제 마진, 정유사 공급가( 보통 휘발유),
% 유류세 등을 이용해 주유소 기름값의 실체를 밝히고 범인이 누구인지 밝혀볼 것이다.*

%% *원유와 정유사 공급가의 상관관계*
plot(date,[oil,supply]);
xlabel('날짜(2009 - 2018)');
ylabel('가격(원)');
title('2009 - 2018 원유, 주유소 공급가','fontsize',15);
legend(' 원유 가격',' 주유소 공급가');

%%
% *원유 가격의 그래프에 비해 주유소 공급가의 그래프가 가파르게 상승하는 것을 볼 수 있다.  
% 보다 정확한 변화의 추이를 보기위해 미분그래프를 사용했다.*
plot(date,[oilDx,supplyDx]);
xlabel('날짜(2009 - 2018)');
ylabel('가격 변화 미분값');
title('원유, 주유소 공급값의 변화 추이','fontsize',15);
legend(' 원유 값 변화 추이',' 주유소 공급가 변화 추이');

%%
% *육안으로 값의 구분 안되는데 이거 적분하면 해결되나? (주유소 공급가 미분값 - 원유 미분값)을 적분한게 양수가 나오면 원유값에 비해 주유소 공급가가 
% 높게 책정되었다는게 객관적으로 증명가능한가? 우리의 의심이 근거가 잇음을 밝히고 시작하는게 깔끔해 보여서 이렇게 구성해봄 trapz라는 함수 적분하는
% 거라던데 한번 써보니까 양수값 나오긴 함 누가 팩트체크좀 수학적으로 해줘 ㅋㅋ*
%% content 2

%% content 3

%% 충격적인 진실

%% 결론
% *정부가 나쁜 놈들이었다 ㅡㅡ*
