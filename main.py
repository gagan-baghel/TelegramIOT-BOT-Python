import content as keys
import requests 
from telegram.ext import *
import response as R
print(" Your Water Tank Bot is Online")
def start_command(update,context):
        update.message.reply_text(" Neotank-Online ")
        update.message.reply_text(" Hey! Its NeoTank ")
        update.message.reply_text('Type What you want to know about your WaterTank \n -- Status / waterlevel --')
        update.message.reply_text("For information about your tank \n -- UserName / Tankinfo --")
        update.message.reply_text("For Hardware health  \n -- Health --")
        
def help_command(update,context):
        update.message.reply_text('For help you should contact to our Customercare service 888-345-232') 
        
def handle_message(update,context):
	text= str(update.message.text).lower()
	response = R.sampleresponse(text)
	update.message.reply_text(response)
 
def error(update,context):
        print(f"Update { update } caused error {context.error}")
        
def main():
        updater = Updater(keys.B_KEY,use_context=True)
        dp = updater.dispatcher
        dp.add_handler(CommandHandler("start",start_command))
        dp.add_handler(CommandHandler("help",help_command))
        dp.add_handler(MessageHandler(Filters.text,handle_message))
        dp.add_error_handler(error )
        updater.start_polling()
        while(1):
                R.cally()
                if(int((requests.get('http://techvegan.in/neotank/level.txt')).text)>75):
                        requests.get('http://api.callmebot.com/start.php?source=web&user=@janhvi_4&text=water tank is full&lang=en-US-Standard-B')
        updater.idle()
main()
        