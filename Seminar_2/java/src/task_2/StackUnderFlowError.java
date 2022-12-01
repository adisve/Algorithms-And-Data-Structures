package task_2;

public class StackUnderFlowError extends VirtualMachineError { 
        /**
        * Constructs a {@code StackUnderFlowError} with no detail message.
        */
        public StackUnderFlowError() {
                super();
        }

        /**
        * Constructs a {@code StackUnderFlowError} with the specified
        * detail message.
        *
        * @param s -> The detailed message.
        */
        public StackUnderFlowError(String s) {
                super(s);
        }
}
    