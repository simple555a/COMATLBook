import com.ms.wfc.core.*;
import com.ms.wfc.ui.*;
import com.ms.lang.Delegate;
/**
 * This class is designed to be packaged with a COM DLL output format.
 * The class has no standard entry points, other than the constructor.
 * Public methods will be exposed as methods on the default COM interface.
 * @com.register ( clsid=E7448F81-AE53-11D3-8088-000000000000, typelib=E7448F82-AE53-11D3-8088-000000000000 )
 */
public class Class1
{
	// TODO: Add additional methods and code here

	EventHandler m_Event1;
	private long m_Property1;
	public void addOnEvent1(EventHandler value)
	{
		m_Event1 = (EventHandler)Delegate.combine(m_Event1, value);
	}

	public long getProperty1()
	{
		// TODO: Add your own implementation.
		return m_Property1;
	}

	public static class ClassInfo extends com.ms.wfc.core.ClassInfo
	{
		public static final EventInfo event1 = new EventInfo(
			Class1.class, "event1", EventHandler.class);
		public static final PropertyInfo property1 = new PropertyInfo(
			Class1.class, "property1", long.class);
		public void getEvents(IEvents events)
		{
			super.getEvents(events);
			events.add(event1);
		}

		public void getProperties(IProperties props)
		{
			super.getProperties(props);
			props.add(property1);
		}

		public void method1(long lArg)
		{
			//onEvent1(new Event());
		}
	}

	protected void onEvent1(Event event)
	{
		if (m_Event1 != null) m_Event1.invoke(this, event);
	}

	public void removeOnEvent1(EventHandler value)
	{
		m_Event1 = (EventHandler)Delegate.remove(m_Event1, value);
	}

	public void setProperty1(long value)
	{
		// TODO: Add your own implementation.
		m_Property1 = value;
	}
}
