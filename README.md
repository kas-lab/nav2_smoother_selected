# nav2_smoother_selected

You can use this plugin to check if a smoother selected in combination with the SmootherSelector BT node, allowing you to disable and enable smoothing at runtime.

For example:

```
<SmootherSelector selected_smoother="{selected_smoother}" default_smoother="simple_smoother" topic_name="smoother_selector"/>
<RateController hz="1.0">
<RecoveryNode number_of_retries="1" name="ComputePathToPose">
	<Sequence name="ComputeAndSmoothPath">
	<ComputePathToPose goal="{goal}" path="{path}" planner_id="{planner_id}"/>
	<Fallback name="SmootherFallback">
	<Inverter>
		<IsSmootherSelected/>
	</Inverter>
	<SmoothPath unsmoothed_path="{path}" smoothed_path="{path}" smoother_id="{selected_smoother}"/>
	</Fallback>
```

If you set the selected_smoother to 'disabled', then IsSmootherSelected will return FAILURE, which when inverted (becomes SUCCESS) in the fallback leads to the SmoothPath not being ticked.

To set this up just make sure to build this package, and add this entry:
```
      - nav2_is_smoother_selected_bt_node
```
To the plugin_lib_names parameter of the bt_navigator node from nav2.
