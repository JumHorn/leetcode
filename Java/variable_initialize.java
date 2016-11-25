public class variable_initialize{ 
	public void pupAge(){
		int age;
		age = age + 7;
		System.out.println("小狗的年龄是 : " + age);
	}

	public static void main(String args[]){
		variable_initialize test= new variable_initialize();
		test.pupAge();
	}
}
