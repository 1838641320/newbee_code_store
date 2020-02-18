import numpy as np
import matplotlib.pyplot as plt
def main():
	# 设置x和y的坐标范围
    x=np.arange(-3,3,0.005)
    y=np.arange(-3,3,0.005)
    # 转化为网格
    x,y=np.meshgrid(x,y)
    e=np.exp(1)
    z=(0.2*(e**(-(y+1)**(2))+1))/(e**(100*(y+1)-16)+1)+(1.5*e**(-0.62*(y-0.16)**(2)))/(e**(-20*(5*y-1))+1)+(0.1)/(e**(2*(10*y-1.2)**(4)))+(0.8*(y-0.2)**(3)+1.5)/((e**(-(100*(y+1)-16))+1)*(e**(20*(5*y-1))+1))-x
    plt.contour(x,y,z,0)
    plt.show()


main()
# 绘制的时候要保证x，y，z的维度相同