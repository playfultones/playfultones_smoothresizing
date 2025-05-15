namespace PlayfulTones
{
    ComponentResizer::ComponentResizer (juce::Component& componentToResize)
        : component (componentToResize)
    {
    }

    void ComponentResizer::setTransformedBounds (const juce::Rectangle<float>& bounds)
    {
        auto compBounds = bounds.getSmallestIntegerContainer();
        auto transform = getRectTransform (compBounds.toFloat(), bounds);

        component.setTransform (juce::AffineTransform());
        component.setBounds (compBounds);
        component.setTransform (transform);
    }

    juce::AffineTransform ComponentResizer::getRectTransform (const juce::Rectangle<float>& source,
        const juce::Rectangle<float>& target)
    {
        float newX = target.getX();
        float newY = target.getY();

        float scaleX = target.getWidth() / source.getWidth();
        float scaleY = target.getHeight() / source.getHeight();

        return juce::AffineTransform::translation (-source.getX(), -source.getY())
            .scaled (scaleX, scaleY)
            .translated (newX, newY);
    }

    void ComponentResizer::drawFittedTextFloat (juce::Graphics& g,
        const juce::String& text,
        juce::Rectangle<float> area,
        juce::Justification justification,
        const int maximumNumberOfLines,
        const float minimumHorizontalScale)
    {
        if (text.isNotEmpty() && (!area.isEmpty()) && g.getInternalContext().clipRegionIntersects (area.toNearestInt()))
        {
            juce::GlyphArrangement arr;
            arr.addFittedText (g.getInternalContext().getFont(), text, area.getX(), area.getY(), area.getWidth(), area.getHeight(), justification, maximumNumberOfLines, minimumHorizontalScale);

            arr.draw (g);
        }
    }
} // namespace PlayfulTones