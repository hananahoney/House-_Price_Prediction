#i19-0542, Mohammad Shazil Mahmood, CS-E
#i19-2172, Hannan Ali, CS-E
#k19-1257, Umer Rashid, CS-E

import pandas as pd
from sklearn import linear_model
import os
import time
start_time = time.time()

path = __file__
file_name=path.split("\\")
dir=""
for i in range(len(file_name)-1):
    dir=dir+file_name[i]+"\\"

print("Training....")
df = pd.read_csv ((dir+"final_training.csv"))
x=df[['Level', 'Area', 'Floor', 'Rooms', 'Pool', 'Garage', 'Garden', 'Age', 'Theater']]
y=df['Price(Million-USD)']
regr = linear_model.LinearRegression()
regr.fit(x.values, y.values)

while True:
    print("\nEnter 'Q' to Quit")
    print("Enter any other key to Predict House Price")
    task=input()
    if (task == 'Q' or task == 'q'):
        break

    lvl=""
    while not(lvl=='1' or lvl=='2' or lvl=='3'):
        print("\nSelect the location of House")
        print("Enter '1' for Rural Area")
        print("Enter '2' for Middle Class Area")
        print("Enter '3' for Upper Class Area")
        lvl=input()

    print("\nEnter The Area of House (Sq-ft) (+ve value, >0)")
    area_input=input()

    print("\nEnter No. of Floors (+ve value, >0)")
    floor_input=input()

    print("\nEnter No. of Rooms (+ve value, >0)")
    rooms_input=input()

    pool_input=""
    while not(pool_input=='0' or pool_input=='1'):
        print("\nEnter if House have a Pool or Not")
        print("Enter '0' for No")
        print("Enter '1' for Yes")
        pool_input=input()

    print("\nEnter No. of Garages (+ve value, >0)")
    garage_input=input()

    garden_input=""
    while not(garden_input=='0' or garden_input=='1'):
        print("\nEnter if House have a Garden or Not")
        print("Enter '0' for No")
        print("Enter '1' for Yes")
        garden_input=input()

    print("\nEnter Age of House (Years) (+ve value, >0)")
    age_input=input()

    theater_input="" 
    while not(theater_input=='0' or theater_input=='1'):
        print("\nEnter if House have a Theater or Not")
        print("Enter '0' for No")
        print("Enter '1' for Yes")
        theater_input=input()

    Prediction_Temp_File = open((dir+"Regression_Answer_Temp.csv"), "w")
    Prediction_Temp_File.write("Level,Area,Floor,Rooms,Pool,Garage,Garden,Age,Theater\n")
    msg=str(lvl) + "," + str(area_input) +  "," + str(floor_input) +  "," + str(rooms_input) +  "," + str(pool_input) +  "," + str(garage_input) +  "," + str(garden_input) +  "," + str(age_input) +  "," + str(theater_input) + "\n"
    Prediction_Temp_File.write(msg)
    Prediction_Temp_File.close()

    df = pd.read_csv ((dir+"Regression_Answer_Temp.csv"))
    x1=df[['Level', 'Area', 'Floor', 'Rooms', 'Pool', 'Garage', 'Garden', 'Age', 'Theater']]
    predicted_price = regr.predict([x1.values[0]])

    print("\nPrediction Summary:-")
    print("Predicted Price (Million USD): ", predicted_price)
    print("Predicted Price (Million PKR, @176.38): ", (predicted_price*176.38))
    if lvl=='1':
        print("Location: Rural")
    elif lvl=='2':
        print("Location: Middle Class")
    elif lvl=='3':
        print("Location: Upper Class")

    print("Area (Sq-Ft): ", area_input, "\nFloors: ", floor_input, "\nRooms: ", rooms_input, "\nGarage: ", garage_input, "\nAge of House(Years): ", age_input)

    if pool_input=='0':
        print("Pool: No")
    elif pool_input=='1':
        print("Pool: Yes")

    if garden_input=='0':
        print("Garden: No")
    elif garden_input=='1':
        print("Garden: Yes")

    if theater_input=='0':
        print("Theater: No")
    elif theater_input=='1':
        print("Theater: Yes")
    
    if os.path.exists((dir+"Regression_Answer_Temp.csv")):
        os.remove((dir+"Regression_Answer_Temp.csv"))


