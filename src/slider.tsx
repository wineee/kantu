import { CType, fmt, useState, Widget, WidgetProps } from "@lcui/react";
import "./slider.scss";

export default function Slider(props: WidgetProps) {
  const [percentage] = useState(0, CType.Double);

  return (
    <Widget
      className="slider"
      onMouseDown="slider_on_mousedown"
      onMouseMove="slider_on_mousemove"
      onMouseUp="slider_on_mouseup"
      {...props}
    >
      <Widget className="slider-track bg-slate-500">
        <Widget
          $ref="bar"
          className="slider-bar bg-sky-500"
          style={{ width: fmt(percentage, "%") }}
        />
      </Widget>
      <Widget
        $ref="thumb"
        className="slider-thumb bg-sky-500 border-slate-600"
      />
    </Widget>
  );
}
