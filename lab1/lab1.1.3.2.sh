#ps -aux

if [ -z "$1" ]
then
echo "Invalid PID. Please enter a valid PID."
exit 1
fi

PROCESS_NAME=$(ps -p $1 -o comm=)

if [ -z "$PROCESS_NAME" ]
then
echo "Invalid PID. Please enter a valid PID."
exit 1
else
ps -p $1 -o comm,%mem,user,time | sudo tee /var/log/SURNAME.log
fi



