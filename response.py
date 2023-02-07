from datetime import datetime
import requests
import time as t
def cally():
        if(int((requests.get('http://techvegan.in/neotank/level.txt')).text)>75):
                # requests.get('http://api.callmebot.com/start.php?source=web&user=@prachimu&text=watertank is about to full &lang=en-US-Standard-B')
                requests.get('http://api.callmebot.com/start.php?source=web&user=@janhvi_4&text=water tank is full&lang=en-US-Standard-B')
                t.sleep(65)
        else:
                print("watertank is filling")

                
def sampleresponse(input_text):
        usermessage = str(input_text).lower()
        if usermessage in ("username","tankid"): 
                return "Name : Prachi Mundharikar \nTankId a00 "
        if usermessage in ("health"): 
                return "last health detail 99% \nMaintainance Month January 1"
        if usermessage in ("status","waterlevel"):
                if(int((requests.get('http://techvegan.in/neotank/level.txt')).text)>75):
                        return "The level of your waterTank is "+(requests.get('http://techvegan.in/neotank/level.txt')).text + "% \n your tank is about to full" 
                elif(int((requests.get('http://techvegan.in/neotank/level.txt')).text)==50):
                        return "The level of your waterTank is "+(requests.get('http://techvegan.in/neotank/level.txt')).text + "% \nHalf Filled" 
                else:
                        return "The level of your waterTank is "+(requests.get('http://techvegan.in/neotank/level.txt')).text + "% \n you shoud off the filler after few minutes" 
        return "i don't understand"