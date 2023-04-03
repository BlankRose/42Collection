try:
	import smtplib, ssl, time
	from os.path import basename
	import os.path as Path
	from email.mime.application import MIMEApplication
	from email.mime.multipart import MIMEMultipart
	from email.mime.text import MIMEText
	from email.utils import formatdate
	from getpass import getpass
except ImportError:
    print("This script needs the SMTPlib, SSL and GetPass modules to be installed")
    exit(1)

sender = input('Enter your email: ')
if not len(sender):
	print("Please specify a sender and receptionist!")
	exit(1)

recept = input('Enter reception email: ')
if not len(recept):
	recept = sender

password = getpass('Enter your email password: ')

try:
	IP = 'smtp.office365.com'
	PORT = 587

	context = ssl.SSLContext(ssl.PROTOCOL_TLS)
	with smtplib.SMTP(IP, PORT) as server:

		server.starttls(context=context)
		server.login(sender, password)
		print ('Server Connection: Success!')

		subject = input("Enter the subject: ")
		if not len(subject):
			subject = "SMTP Python Test"

		text = input("Enter your message: ")
		if not len(text):
			text = "This is a test of SMTP!"

		file = input("Enter a file to attach: ")
		if not len(file) or not Path.exists(file):
			file = None

		msg = MIMEMultipart()
		msg['From'] = sender
		msg['To'] = recept
		msg['Date'] = formatdate(localtime = True)
		msg['Subject'] = "SMTP Python Test"
		msg.attach(MIMEText(text))

		if file:
			with open(file, "rb") as fil:
				part = MIMEApplication(
					fil.read(),
					Name=basename(file)
				)
				part['Content-Disposition'] = 'attachment; filename="%s"' % basename(file)
				msg.attach(part)

		print(f"Sending: \"{msg}\"")
		server.sendmail(sender, [recept], msg.as_string())
		print ('Email successfully sent!')
		server.quit()

except smtplib.SMTPServerDisconnected:
	print("Connection unexpectedly closed!")
except smtplib.SMTPAuthenticationError:
	print("Either the specified mail or password is wrong!")
except ConnectionRefusedError:
	print("Connection has been refused!")
except:
	print("An unknown error occured!")
