#ps -aux
echo "Please enter the PID of the process: "
read PID

# Check if the PID is valid
if [ -z "$PID" ]
then
echo "Invalid PID. Please enter a valid PID."
exit 1
fi

PROCESS_NAME=$(ps -p $PID -o comm=)

if [ -z "$PROCESS_NAME" ]
then
echo "Invalid PID. Please enter a valid PID."
exit 1
else
ps -p $PID -o comm,%mem,user,time | sudo tee /var/log/SURNAME.log
fi



